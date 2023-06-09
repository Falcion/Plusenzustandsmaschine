name: Documentation Fix
description: Use this template for proposing documentation fixes/improvements.
labels: "area/docs"
title: "[DOC-FIX]"

body:
  - type: markdown
    attributes:
      value: |
        Thank you for submitting an issue. Please refer to our [issue policy](https://www.github.com/mlflow/mlflow/blob/master/ISSUE_POLICY.md) for information on what types of issues we address.
        **Please fill in this documentation issue template to ensure a timely and thorough response.**
  - type: dropdown
    id: contribution
    attributes:
      label: Willingness to contribute
      description: Project encourages documentation fix contributions. Would you or another member of your organization be willing to contribute a fix for this documentation issue?
      options:
        - Yes. I can contribute a documentation fix independently.
        - Yes. I would be willing to contribute a document fix with guidance from the project's community.
        - No. I cannot contribute a documentation fix at this time.
    validations:
      required: true
  - type: textarea
    attributes:
      label: URL(s) with the issue
      description: |
        Please provide a link to the documentation entry in question.
    validations:
      required: true
  - type: textarea
    attributes:
      label: Description of proposal (what needs changing)
      description: |
        Provide a clear description. Why is the proposed documentation better?
    validations:
      required: true